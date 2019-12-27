import java.util.Scanner;

class Util
{
    static int min(int x,int y,int z) {
        if (x <= y && x <= z) return x;
        if (y <= x && y <= z) return y;
        else return z;
    }
    static int LevensteinDist(String str1, String str2, int m, int n) {
        int mat[][] = new int[m+1][n+1];
        mat[0][0] = 0;
        for(int i = 1; i <= m; i++){
            mat[i][0] = mat[i-1][0] + str1.charAt(i-1) - 96;
        }
        for(int j = 1; j <= n; j++){
            mat[0][j] = mat[0][j-1] + str2.charAt(j-1) - 96;
        }

        for (int i=1; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (str1.charAt(i-1) == str2.charAt(j-1))
                    mat[i][j] = mat[i-1][j-1];
                else
                    mat[i][j] = min(mat[i][j-1] + str2.charAt(j-1) - 96,
                            mat[i-1][j] + str1.charAt(i-1) - 96,
                            mat[i-1][j-1] + Math.abs(str1.charAt(i-1) - str2.charAt(j-1)));
            }
        }
        out(mat);
        return mat[m][n];
    }
    static void out(int[][] matrix){
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 1 string : ");
        String str1 = sc.nextLine();
        System.out.print("Enter 2 string : ");
        String str2 = sc.nextLine();
        System.out.println("Levenstein distance : " + LevensteinDist( str1 , str2 , str1.length(), str2.length()) );

    }
}
