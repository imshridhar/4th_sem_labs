import java.sql.*;

public class StudentDB {
    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3306/school";
        String user = "root";
        String pass = "root"; 

        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            
            Connection con = DriverManager.getConnection(url, user, pass);
            System.out.println("Connected to database!");

            Statement stmt = con.createStatement();

            
            stmt.executeUpdate("INSERT INTO student(name, age) VALUES('shridhar', 20)");

            
            ResultSet rs = stmt.executeQuery("SELECT * FROM student WHERE id=1");
            while (rs.next()) {
                System.out.println("Name: " + rs.getString("name"));
                System.out.println("Age: " + rs.getInt("age")); 
            }

            
            stmt.executeUpdate("DELETE FROM student WHERE id=1");

            con.close();
        } catch (Exception e) {
                        System.out.println("❌ Error connecting to MySQL:");
            e.printStackTrace();
        }
    }
}