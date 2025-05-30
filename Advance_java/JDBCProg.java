//File Name : JDBCProg.java
 import java.io.*;
 import java.sql.*;
 public class JDBCProg{
 public static void main(String[] args) throws Exception
 {
 String JDBC_driver = "com.mysql.cj.jdbc.Driver";
 String url = "jdbc:mysql://localhost:3306/mdbase";
 String username = "root";
 String password = "root";
 String query1 = "create table stud (roll int(2), name varchar(10), marks int(2))";
 String query2 = "insert into stud (roll, name, marks) values (3, 'ABC', 20), (1,'PQR', 15), (2,'XYZ', 30)";
 String query3 = "select * from stud order by roll";
 String query4 = "drop table stud";
 Class.forName(JDBC_driver);
 Connection con = DriverManager.getConnection(url,username,password );
 System.out.println("Connection Established successfully");
 Statement st = con.createStatement();
 st.execute(query1);
 st.executeUpdate(query2);
 ResultSet rs = st.executeQuery(query3);
 while(rs.next())
 System.out.println(rs.getInt(1)+" "+rs.getString(2) +" "+rs.getInt(3)) ;
 st.execute(query4);
 con.close();
 System.out.println("Connection Closed....");
 }
 }