//  Program to demonstrate different String methods.

public class stringMethods 
{
	public static void main(String[] args) 
	{
		String s1="This is a Good Course";
		String s2="ANT";
		String s3="Ant";

		int m, n;
		//boolean x;
		char ch;
		String s= new String();

		n=s1.length();  // ---- length of string
		System.out.println("Lenght of String S1="+n);

		ch= s1.charAt(8); // -- Character at a location
		System.out.println("Character at specified location="+ch);
						                   // --- equals with and without ignoring cases
		System.out.println("Strings S2=S3 without ignoring case is "+s2.equals(s3)); 
	 	System.out.println("Strings S2=S3 with ignoring case is "+s2.equalsIgnoreCase(s3));

		System.out.println("String S1 starts with This = "+s1.startsWith("This"));
		System.out.println("String S1 ends with Course = "+s1.endsWith("Course"));

		System.out.println("String S2 in Upper case = "+s2.toUpperCase());
		System.out.println("String S1 in Lower case = "+s1.toLowerCase());

		System.out.println("Index of specified sub-string = "+s1.indexOf("Good"));
		
		
		System.out.println("String after replacement of sub-string = "+s1.replace("Good", "Bad"));

	}

}