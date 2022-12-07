/*
 * main.c
 *
 *  Created on: 6 de dez de 2022
 *      Author: r.freitas
 */
#include <stdint.h>
#include <stdio.h>

struct carModel{
	uint32_t carNumber;
	uint32_t carPrice;
	uint16_t carMaxSpeed;
	float carWeight;
};

int main (void){
	struct carModel carBMW = {2021,15000,220,1330}; //C89 method. Order is important.
	//struct carModel carBMW2 = {.carNumber=2021,.carWeight=1330,.carMaxSpeed=220,.carPrice=15000};	//C99 method using designated initializers
	struct carModel carFord = {4031,35000,160,1900.96};
	struct carModel carHonda = {.carWeight=90.90,.carPrice=15000};

	printf("Detail of car BMW is as follows\n");
	printf("carNumber = %u\n",carBMW.carNumber);
	printf("carPrice= %u\n",carBMW.carPrice);
	printf("carMaxSpeed = %u\n",carBMW.carMaxSpeed);
	printf("carWeight = %f\n\n",carBMW.carWeight);

	printf("Sizeof of struct carModel is %I64u\n\n",sizeof(struct carModel));
	//'%I64u' expects argument of type 'long long unsigned int', but argument 2 has type 'unsigned int'

	printf("Detail of car Ford is as follows\n");
	printf("carNumber = %u\n",carFord.carNumber);
	printf("carPrice= %u\n",carFord.carPrice);
	printf("carMaxSpeed = %u\n",carFord.carMaxSpeed);
	printf("carWeight = %f\n\n",carFord.carWeight);

	carHonda.carNumber = 1010;
	printf("Detail of car Honda is as follows\n");
	printf("carNumber = %u\n",carHonda.carNumber);
	printf("carPrice= %u\n",carHonda.carPrice);
	printf("carMaxSpeed = %u\n",carHonda.carMaxSpeed);
	printf("carWeight = %f\n\n",carHonda.carWeight);

	getchar();

}

