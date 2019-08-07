// java 의 GIMPLE파일을 보기 위한 예제코드이다.
// gcj -o JavaTest JavaTest.java --main=JavaTest -fdump-tree-all 을 이용하여 컴파일 해야한다.

public class JavaTest {
    public static void main( String args[]) {
        int i, j, k;

        j = 0;
        k = 0;

        for (i=0; i < 10; i++ ){
            if ((i % 2) != 0) {
                j += 1;
            }else {
                k += 1;
            }

            System.out.println("j = " + j + ", k = " + k );
        }
    }
}
