import java.util.ArrayList;

public class test {
	public static Integer[] sort(Integer[] dates) {
		ArrayList<Integer> list = new ArrayList<>();
		Integer last = null;
		boolean insert;
		for(Integer d : dates) {
			insert = false;
			if(last == null) {
				list.add(d);
			} else {
				for(int i = 0; i < list.size(); i++) {
					if(d < list.get(i)) {
						list.add(i, d);
						insert = true;
						break;
					}
				}
				if(!insert) {
					list.add(d);
				}
			}
			last = d;
		}
		return list.toArray(new Integer[list.size()]);
	}

	public static void main(String[] args) {
		Integer[] test = {5, 2, 9, 3, 7, 6, 1, -6, -5, 0, 111, -99};
		Integer[] result = sort(test);
		for(Integer i : result)
			System.out.println(i);
	}
}
