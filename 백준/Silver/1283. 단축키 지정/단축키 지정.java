import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    Scanner scan;
    int optionCnt;

    List<Character> letters;
    String[] inputWord;

    public static void main(String[] args) {
        Main m = new Main();
        m.input();
        m.solution();
    }

    private void input() {
        letters = new ArrayList<>();
        
        scan = new Scanner(System.in);
        this.optionCnt = scan.nextInt();
        scan.nextLine();
        inputWord = new String[this.optionCnt];
        for(int i = 0 ; i < this.optionCnt; i++) {
            inputWord[i] = scan.nextLine();
        }
        scan.close();
    }

    private void solution() {
        List<String> result = new ArrayList<>();
        for(int i = 0; i < this.inputWord.length; i++) {
            String[] splitWord = this.inputWord[i].split(" ");
            boolean isValid = false;
            String text = "";
            for(int j = 0; j < splitWord.length; j++) {
                String word = splitWord[j];
                char firstLetter = word.toUpperCase().charAt(0);
                // 첫글자
                if(!this.letters.contains(firstLetter) && !isValid) {
                    this.letters.add(firstLetter);
                    text += this.format(word, 0) + " ";
                    isValid = true;
                    continue;
                }
                text += word + " ";
            }

            if(!isValid) {
                text = "";
                boolean isFirst  = false;
                for(int j = 0; j < splitWord.length; j++) {
                    for(char w : splitWord[j].toCharArray()) {
                        if(!this.letters.contains(Character.toUpperCase(w)) && !isFirst)  {
                            isFirst = true;
                            text += "[" + w + "]";
                            this.letters.add(Character.toUpperCase(w));
                            continue;
                        }
                        text += w;
                    }
                    text += " ";
                }
             }
             result.add(text.trim());
        }

        for(String re : result) {
            System.out.println(re);
        }
    }
    
    private String format(String word, int position) {
        char[] charWord = word.toCharArray();
        StringBuilder builder = new StringBuilder();
        for(int i = 0; i < charWord.length; i++) {
            if(i == position) {
                builder.append("[" + charWord[i] + "]");
            }
            else {
                builder.append(charWord[i]);
            }
        }
        return builder.toString();
    }
}
