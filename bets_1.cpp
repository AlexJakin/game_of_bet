// 不考虑内存泄露版
 
#include <iostream>
#include <time.h>

using namespace std;

int cash = 100; // 筹码

void play(int bet){
	char c[3] = {
		'J', 'Q', 'K'
	};
	cout << "洗牌中 ..." <<endl;
	
	// 进行十次随机交换
	srand(time(NULL));
	int i;
	for (int i = 0; i < 5; i ++ ){
		int x = rand() % 3;
		int y = rand() % 3;
		int temp = c[x];
		c[x] = c[y];
		c[y] = temp;
	}
	
	int playersGuess;
	cout << "选择卡牌Q的位置 1 或 2 或 3？请选择：";
	cin >> playersGuess;
	if (c[playersGuess - 1] == 'Q'){
		cash += 3 * bet;
		cout << "恭喜你猜测成功！！！！当前顺序是：" << c[0] << " " << c[1] << " " << c[2] << " " << endl;
		cout << "当前你的现金总额为：" << cash << endl;
	}else{
		cash -= bet;
		cout << "很抱歉呢，你选错了~~~~当前顺序是：" << c[0] << " " << c[1] << " " << c[2] << " " << endl;
		cout << "当前你的现金总额为：" << cash << endl;
	}
}

int main(){
	int bet; // 每轮的押注 
	cout << "欢迎虚拟押注"<<endl;
	cout << "你目前的总金额为：" << cash <<endl;
	while (cash > 0){
		cout << "这次你押注多少？请输入：";
		cin >> bet;
		if (bet == 0 || bet > cash) break; // 倘若没有筹码了或者押注数超过现金则退出
		play(bet);// 开始押注 
		
		cout << "********************************************************" << endl;
	}
	return 0;
} 