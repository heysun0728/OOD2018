import java.io.*;
public class palidrome{
	public static void main(String args[]){
		String s=new String(args[0]);
		int head=0;
		int tail=s.length()-1;
		s=s.toLowerCase();
		while(head<tail){
			while(!Character.isLetter(s.charAt(head)) && head<tail) head++;
			while(!Character.isLetter(s.charAt(tail)) && head<tail) tail--;
			if(s.charAt(head) != s.charAt(tail)) break;
			head++;tail--;
		}
		if(head>=tail) System.out.println("Yes");
		else System.out.println("No");
	}	
}
