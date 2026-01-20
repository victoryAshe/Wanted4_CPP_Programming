#include <iostream>

const int EXIT_CODE = -1;

void SolutionP4()
{
	while (true)
	{
		int basicSalary = 300;

		int sales;

		std::cout << "판매 금액을 만원 단위로 입력하세요(종료는 -1):";
		std::cin >> sales;
		if (sales == EXIT_CODE) break;

		std::cout << "이번달 급여: " << (basicSalary + sales * 0.15) << "만원\n";

	}
}