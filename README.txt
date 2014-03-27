002Polynomial
=============

Linked List로 표현된 Polynomial



1.c의 내용.

COMP216-002 자료구조응용
LAB #8
2013. 4. 3.
1. 아래의 input.txt로 표현된 두 개의 다항식 A와 B를 더하는 프로그램을 작성하시오. 다항
식은 header node를 갖는 circularly linked list를 사용하여 표현하여야 하
며 동적 메모리 할당을 사용한다.
첫 행의 n은 다항식 A의 항의 수를, m은 다항식 B의 항의 수를 나타낸다. 둘째 행부터 연속
된 n 개의 행은 각각 다항식 A의 항을 나타내고, 뒤이어 나오는 연속된 m개의 행은 각각 다
항식 B의 항을 나타낸다. 각 행의 첫 번째 숫자는 계수를 두 번째 숫자는 지수를 표현한다.
다항식 A와 B의 전체 항의 최대수는 20 이하로 한다.

%vi input.txt 

n m // n은 첫 번째 다항식의 항의 수 (위의 예에서 n의 값은 2)
// m은 두 번째 다항식의 항의 수 (위의 예에서 m의 값은 4)
2 1000
1 0
1 4
10 3
3 2
1 0

%vi output.txt 
2 1000
1 4
10 3
3 2
2 0


2.c의 내용(polynomial만, postfix)
COMP216-002 자료구조응용
LAB #7
2013. 3. 27.

1. 입력 파일에 주어진 infix expression을 postfix expression으로 변환하여 출력하고, 변환
된 postfix expression을 이용하여 산술식을 계산하는 프로그램을 완성하시오. 사용하는 연산
자는 +, -, /, *, %, &&, ||, ==, !=, <, >, <=, >= 이며 left parenthesis와 right
parenthesis를 고려한다. 산술식을 구성하는 연산자, 피연산자(10이하 양의 정수), 괄호는
space로 구분되며 전체 50개 이하로 한다.

%vi input.txt
( 3 != 9 ) && ( 4 >= 9 ) // 답은 0
%vi input.txt
( 3 + 4 ) * 5 + 6 / ( 7 + 8 * 9 ) + 1 // 답은 36


3.c의 내용(polynimial만, prefix)
COMP216-002 자료구조응용
HW #3
(Due: 2013. 4. 3. 1:30pm)
2013. 3. 27.
1. 입력 파일에 주어진 infix expression을 prefix expression으로 변환하여 출력하고, 변환
된 prefix expression을 이용하여 산술식을 계산하는 프로그램을 완성하시오. 사용하는 연산
자는 +, -, /, *, %, &&, ||, ==, !=, <, >, <=, >= 이며 left parenthesis와 right
parenthesis를 고려한다. 산술식을 구성하는 연산자, 피연산자(10이하 양의 정수), 괄호는
space로 구분되며 전체 50개 이하로 한다. (Hint: prefix 형태로 변환할 때는 스택을 두 개
사용한다.)

%vi input.txt
( 3 != 9 ) && ( 4 >= 9 ) // 답은 0
%vi input.txt
( 3 + 4 ) * 5 + 6 / ( 7 + 8 * 9 ) + 1 // 답은 36
