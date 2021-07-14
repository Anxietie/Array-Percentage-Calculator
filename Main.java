package com.me;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter values in one line separated by a space: ");
		String[] arr = scanner.nextLine().split(" ");
		Map<Integer, Integer> m = new HashMap<Integer, Integer>();
		for (int i = 0; i < arr.length; i++) {
			if(m.get(Integer.parseInt(arr[i]))==null) {
				m.put(Integer.parseInt(arr[i]),1);
			}
			else {
				m.put(Integer.parseInt(arr[i]), m.get(Integer.parseInt(arr[i]))+1);
			}
		}
		Map.Entry<Integer, Integer> maxEntry = null;
		for (Map.Entry<Integer, Integer> entry : m.entrySet()) {
			if (maxEntry == null || entry.getValue().compareTo(maxEntry.getValue()) > 0)
		    {
		        maxEntry = entry;
		    }
		}
		System.out.println("Occurences: "+m.toString());
		System.out.println(maxEntry.getKey()+" has the highest chance of %"+((float)maxEntry.getValue()/arr.length)*100);
		scanner.close();
	}
}