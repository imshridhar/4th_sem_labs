import java.sql.*;
import java.util.Scanner;

public class StudentDBShort {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/school", user = "root", pass = "root";
        try (Connection con = DriverManager.getConnection(url, user, pass);
             Scanner sc = new Scanner(System.in)) {

            Class.forName("com.mysql.cj.jdbc.Driver");
            System.out.println("✅ Connected to MySQL");

            while (true) {
                System.out.println("\n1.Insert 2.View All 3.Search 4.Update 5.Delete 6.Exit");
                int ch = sc.nextInt();
                sc.nextLine(); 

                switch (ch) {
                    case 1 -> {
                        System.out.print("Name: "); String name = sc.nextLine();
                        System.out.print("Age: "); int age = sc.nextInt();
                        PreparedStatement ps = con.prepareStatement("INSERT INTO student(name, age) VALUES(?, ?)");
                        ps.setString(1, name); ps.setInt(2, age);
                        ps.executeUpdate(); System.out.println("✅ Inserted.");
                    }
                    case 2 -> {
                        ResultSet rs = con.createStatement().executeQuery("SELECT * FROM student");
                        while (rs.next())
                            System.out.println("ID: " + rs.getInt("id") + ", Name: " + rs.getString("name") + ", Age: " + rs.getInt("age"));
                    }
                    case 3 -> {
                        System.out.print("Search name: "); String sname = sc.nextLine();
                        PreparedStatement ps = con.prepareStatement("SELECT * FROM student WHERE name LIKE ?");
                        ps.setString(1, "%" + sname + "%");
                        ResultSet rs = ps.executeQuery();
                        while (rs.next())
                            System.out.println("ID: " + rs.getInt("id") + ", Name: " + rs.getString("name") + ", Age: " + rs.getInt("age"));
                    }
                    case 4 -> {
                        System.out.print("Update ID: "); int uid = sc.nextInt();
                        System.out.print("New Age: "); int newAge = sc.nextInt();
                        PreparedStatement ps = con.prepareStatement("UPDATE student SET age=? WHERE id=?");
                        ps.setInt(1, newAge); ps.setInt(2, uid);
                        ps.executeUpdate(); System.out.println("✅ Updated.");
                    }
                    case 5 -> {
                        System.out.print("Delete ID: "); int did = sc.nextInt();
                        PreparedStatement ps = con.prepareStatement("DELETE FROM student WHERE id=?");
                        ps.setInt(1, did);
                        ps.executeUpdate(); System.out.println("✅ Deleted.");
                    }
                    case 6 -> {
                        System.out.println("👋 Exiting."); return;
                    }
                    default -> System.out.println("❌ Invalid choice.");
                }
            }
        } catch (Exception e) {
            System.out.println("❌ Error:");
            e.printStackTrace();
        }
    }
}
