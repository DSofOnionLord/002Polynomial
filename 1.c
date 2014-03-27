#include <stdio.h>
#include <stdlib.h>
//Linked List & Polynomial
typedef struct poly *polyp;
struct poly
{
	float val;
	int deg;
	polyp next;
};

void insert_cl(polyp *head, polyp *top, float i_val, int i_deg)
{

	polyp temp;
	temp = (polyp)malloc(sizeof(*temp));


	(*top)->next = temp;
	temp->val = i_val;
	temp->deg = i_deg;
	temp->next = (*head);

	*top = temp;

}

void RIP(polyp *head)
{
	polyp temp;
	polyp node;
	node = (*head);
	while(1)
	{
		temp = node;
		node = node->next;
		if(node == *head)
		{
			break;
		}
		free(temp);
	}
}

int main()
{
	polyp pol1, pol2;
	polyp result;
	polyp pol1_top, pol2_top, res_top;
	polyp pos1, pos2, r_pos;
	
	int n,m;
	int i;

	float i_val;
	int i_deg;

	FILE * fin  = fopen("input.txt", "r");
	FILE * fout = fopen("output.txt", "w");

	pol1 = (polyp)malloc(sizeof(*pol1));
	pol2 = (polyp)malloc(sizeof(*pol2));
	result = (polyp)malloc(sizeof(*result));

	pol1->deg = -666;
	pol1->next = NULL;

	pol1_top = pol1;

	pol2->deg = -666;
	pol2->next = NULL;

	result->deg = -666;
	result->next = NULL;

	res_top = result;

	pol2_top = pol2;

	fscanf(fin, "%d %d", &n, &m);

	for ( i = 0 ; i < n ; i ++ )
	{
		fscanf(fin, "%f %d", &i_val, &i_deg);
		insert_cl(&pol1, &pol1_top, i_val, i_deg);
	}

	for ( i = 0 ; i < m ; i ++ )
	{
		fscanf(fin, "%f %d", &i_val, &i_deg);
		insert_cl(&pol2, &pol2_top, i_val, i_deg);
	}


	pos1 = pol1;//1번 다항식
	pos2 = pol2;//2번 다항식

	pos1 = pos1 -> next; 
	pos2 = pos2 -> next;



	
	while(1)
	{
		if( n == 0)
		{
			if(pos2 == pol2)//처음으로 돌아올때 끝난다.
			{
				break;
			}
			insert_cl(&result, &res_top, pos2->val, pos2->deg);
			pos2 = pos2 ->next;
		}
		else if( m == 0 )
		{
			if( pos1 == pol1)//처음으로 돌아올때 끝난다.
			{
				break;
			}
			insert_cl(&result, &res_top, pos1->val, pos1->deg);
			pos1 = pos1->next;
		}
		else if( n == 0 && m == 0 )
		{
			break;
		}
		else
		{
			if( pos1 == pol1 && pos2 == pol2)//처음으로 돌아올때 끝난다.
			{
				break;
			}
			if(pos1->deg > pos2->deg)
			{
				insert_cl(&result, &res_top, pos1->val, pos1->deg);
				pos1 = pos1->next;
			}
			else if(pos1->deg == pos2->deg)
			{
				insert_cl(&result, &res_top, (pos1->val + pos2->val), pos1->deg);
				pos1 = pos1->next;
				pos2 = pos2 ->next;
			}
			else
			{
				insert_cl(&result, &res_top, pos2->val, pos2->deg);
				pos2 = pos2 ->next;
			}
		}
	}

	r_pos = result->next;
	while(r_pos->deg != -666)
	{
		fprintf(fout, "%-5g %-5d\n", r_pos->val, r_pos->deg);
		r_pos = r_pos->next;
	}


	if( n != 0 )
		RIP(&pol1);
	else
		free(pol1);

	if( m != 0 )
		RIP(&pol2);
	else
		free(pol2);

	RIP(&result);


	fclose(fin);
	fclose(fout);
	return 0;
}
