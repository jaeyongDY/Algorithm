
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader buf = new  BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.valueOf(buf.readLine());
		
		Map<String, Integer> books = new HashMap<>();
		int max = 0;
		
		for(int i = 0; i < n; i++) {
			String book = buf.readLine();
			books.put(book, books.getOrDefault(book, 0) + 1);
			
			max = Math.max(books.get(book), max);
		}
		
		List<String> result = new ArrayList<>();
		for(Entry<String, Integer> ret : books.entrySet()) {
			if(max == ret.getValue()) {
				result.add(ret.getKey());
			}
		}
		Collections.sort(result);
		System.out.println(result.get(0));
	}

}
