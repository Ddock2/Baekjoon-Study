#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string s = "";
	cin >> s;
	stack<char> l;
	stack<char> r;
	for (int i = 0; i < s.size(); i++) {
		l.push(s[i]);
	}
	int num;
	cin >> num;
	while (num--) {
		char tmp;
		cin >> tmp;
		if (tmp == 'P') {
			char c;
			cin >> c;
			l.push(c);
		}
		else if (tmp == 'L') {
			if (l.empty()) continue;
			else {
				r.push(l.top());
				l.pop();
			}
		}
		else if (tmp == 'B') {
			if (l.empty()) continue;
			else l.pop();
		}
		else if (tmp == 'D') {
			if (r.empty()) continue;
			else {
				l.push(r.top());
				r.pop();
			}
		}
	}
	while (!l.empty()) {
		r.push(l.top());
		l.pop();
	}
	while (!r.empty()) {
		cout << r.top();
		r.pop();
	}
	return 0;
}


// 시간 초과
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//#define MAX_TEXT_LENGTH 600000
//
//int main()
//{	
//	string text;
//	int cursor;
//
//	int remainCommandNumber;
//	char command;
//
//	text.reserve(MAX_TEXT_LENGTH);
//	
//	// 초기입력
//	cin >> text;
//	cursor = (int) text.length();
//
//	// 명령어 수 입력
//	cin >> remainCommandNumber;
//
//	while (remainCommandNumber--)
//	{
//		cin >> command;
//
//		switch (command)
//		{
//			case 'L' :
//				cursor--;
//				if (cursor < 0) cursor++;
//				break;
//			case 'D':
//				cursor++;
//				if (cursor > text.length()) cursor--;
//				break;
//			case 'B':
//				if (cursor != 0)
//				{
//					text.erase(text.begin() + --cursor);
//				}
//				break;
//			case 'P':
//				cin >> command;
//				text.insert(text.begin() + cursor++, command);
//				break;
//		}
//	}
//	
//	cout << text;
//
//	return 0;
//}
