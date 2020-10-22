#include <stdio.h>
  
int main(void)
{
        int system, algorithm, network;
        float average; // float 형으로 변환

        printf("Input the system programming, algortihm, and network score:");
        scanf("%d %d %d", &system, &algorithm, &network);

        average = (float)(system + algorithm + network) / 3; // 평균이 괄호가 없어서 계산이 network/3 이 나머지와 더해짐
	//float로 변경 후 계산해야함

        printf("The average of the three subjects is %.2f.\n", average); // 소수점 두자리 출력이므로, .2f를 이용

        return 0;

}

