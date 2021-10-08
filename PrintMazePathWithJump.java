
                                    // KHUD SE
                            
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
          Scanner scn = new Scanner (System.in);
          int n = scn.nextInt();
          int m = scn.nextInt();
          printMazePaths(1, 1, n, m, "");
          
    }

    // sr - source row
    // sc - source column
    // dr - destination row
    // dc - destination column
    public static void printMazePaths(int sr, int sc, int dr, int dc, String psf) {
        // if(sc>dc || sr>dr){
        //     return;
        // }
        
        if(sc==dc && sr==dr){
            System.out.println(psf);
            return;
        }
        
        
        for(int i=1; i<=dc-sc; i++){
        printMazePaths(sr, sc+i, dr, dc, psf+ "h"+i);
        }
        for(int j=1; j<=dr-sr; j++){
        printMazePaths(sr+j, sc, dr, dc, psf+ "v"+j);
        }
        for(int k=1; k<=dr-sr && k<=dc-sc; k++){
        printMazePaths(sr+k, sc+k, dr, dc, psf + "d"+k);
        }
        
        
    }

}
