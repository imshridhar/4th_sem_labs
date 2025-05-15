import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.*;

public class l8 extends GenericServlet
{
	public void service(ServletRequest req ,ServletResponse res)
	throws ServletException,IOException
	{
		res.setContentType("text/html") ;
		PrintWriter out=res.getWriter();
		String msg=req.getParameter("t1");
		out.println(“Hello ” + msg + "How are you ?”);
	}
}   
