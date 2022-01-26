#include<stdio.h>
#include<string.h>
#include<hamako.h>

#define MaxSize 100	// Upper Limit of Student's Number
#define SbjSize 3		// Number of Subject
#define NameSize 45	// Size of Name
#define RoE 50			// Range of Element
#define MRG 7				// Max Range of Graph

/**
 * @brief
 * DataType
 */
typedef struct {
	int No;
	char name[NameSize];// [0]~[20] => FirstName ,[21] => Space ,[22]~[40] => SecondName
	int sbj[SbjSize];// [0] => JapaneseScore,[1] => MathScore,[2] => EnglishScore
	int rank;
	int graph[7];
}Exam;

/**
 * @brief
 * Accessor List
 */

/*01*/void setName(Exam *student,char name1[],char name2[]);
/*02*/char *getName(Exam *student,char name[]);
/*03*/void setSubjectScore(Exam *student,int sbj,int score);
/*04*/int getSubjectScore(Exam *student,int sbj);
/*05*/int getScoreSum(Exam *student);
/*06*/void setRank(Exam *student,int rank);
/*07*/int getRank(Exam *student);

/**
 * @brief
 * Operation Function List without Accessor
 */
/*01*/void setData(int n,Exam stu[]);
/*02*/void outData(int n,Exam stu[]);
/*03*/void outGraph(int n,int histogram[]);
/*04*/void outScore(int n,Exam stu[]);
/*05*/void setRanking(int n,Exam stu[]);
/*06*/void outLine(int n);
/*07*/void setGraph(int n,int histgram[],Exam stu[]);
/*08*/
/*09*/
/*10*/
/*11*/
/*12*/
/*13*/
/*14*/
/*15*/

int main(){
	int n,judgeStuNumber;
	Exam stu[100];
	int histogram[MRG]={};
	//1.1 => Input Student's Information
	//1.2.1 => Judge Range
	//1.2.2-T => Continue
	//1.2.2-F => Finish with Error
	n = getint("Input Student's Number\n");
	if(n > MaxSize){
		printf("Abnormal Data Entried\n");
		return(1);
	}
	setData(n,stu);
	//2.1 => Data Complete
	//2.2 => Set Rank
	setRanking(n,stu);
	//2.3 => set Graph
	setGraph(n,histogram,stu);
	//3.1 => Data out
	outScore(n,stu);
	outGraph(n,histogram);
	return(0); // Program Completed
}

// ---------Accessor List---------

/**
 * @brief Set the Name object
 *
 * @param student
 * @param name1
 * @param name2
 */
void setName(Exam *student,char name1[],char name2[]){
	strcat(name1," ");
	strcat(name1,name2);
	strcpy(student->name,name1);
	// strcat(student->name,name1);
	// strcat(student->name," ");
	// strcat(student->name,name2);
	return;
}

/**
 * @brief Get the Name object
 *
 * @param student
 * @param name
 * @return char*
 */
char *getName(Exam *student,char name[]){
	name = student->name;
	return(name);
}

/**
 * @brief Set the Subject Score object
 *
 * @param student
 * @param sbj
 * @param score
 */
void setSubjectScore(Exam *student,int sbj,int score){
	student->sbj[sbj] = score;
	return;
}

/**
 * @brief get the Subject Score object
 *
 * @param student
 * @param sbj
 *
 * @return int
 */
int getSubjectScore(Exam *student,int sbj){
	return(student->sbj[sbj]);
}

/**
 * @brief get the Score Sum object
 *
 * @param student
 *
 * @return int
 *
 */
int getScoreSum(Exam *student){
	int sum=0;
	for(int i = 0 ; i < SbjSize ; i++){
		sum += student->sbj[i];
	}
	return(sum);
}

/**
 * @brief set the Rank object
 *
 * @param student
 * @param rank
 */
void setRank(Exam *student,int rank){
	student->rank = rank;
	return;
}

/**
 * @brief get the Rank object
 *
 * @param student
 *
 * @return int
 */
int getRank(Exam *student){
	return(student->rank);
}

// -----------Operation Function List without Accessor-----------

/**
 * @brief Set the Data object
 *
 * @param n
 * @param stu
 */
void setData(int n,Exam stu[]){
	char buff[256] = {};
	char fname[20] = {},sname[20] = {};
	int score[4] = {},no;
	for(int i = 0 ; i < n ; i++){
		fgets(buff,sizeof(buff),stdin);
		sscanf(buff, "%d %s %s %d %d %d",&no,&fname,&sname,&score[0],&score[1],&score[2]);
		no--;
		setName(&stu[no],fname,sname);
		for(int i=0;i<SbjSize;i++){
			setSubjectScore(&stu[no],i,score[i]);
		}
	}

	return;
}

/**
 * @brief out the Graph Data object
 *
 * @param n
 * @param histogram
 */
void outGraph(int n,int histogram[]){
	for(int i=0;i<MRG;i++){
		if(i < MRG-1){
			printf("[%3d] - [%3d] [%3d] ",50*i,50*i+49,histogram[i]);
		}else{
			printf("[%3d]         [%3d] ",50*i,histogram[i]);
		}
		outLine(histogram[i]);
		printf("\n");
	}
}
/**
 * @brief set the Graph Data object
 *
 * @param n
 * @param histogram
 * @param stu
 */
void setGraph(int n,int histogram[],Exam stu[]){
	int j,sum;
	for(int i=0;i<n;i++){
		j = 0;
		sum = getScoreSum(&stu[i]);
		while((j*RoE)-1 < sum&& j < MRG){
			j++;
		}
		histogram[j-1]++;
	}
	return;
}

/**
 * @brief out the Score object
 *
 * @param n
 * @param stu
 */
void outScore(int n,Exam stu[]){
	int jap,math,eng,sum,rank,japS=0,mathS=0,engS=0,sumS=0;
	char name[41];
	printf("|  No | Name                                      |  Japanese |      Math |   English |       Sum |      Rank |   Average |\n");
    printf("|-------------------------------------------------------------------------------------------------------------------------|\n");
    for(int i=0;i<n;i++){
		jap = getSubjectScore(&stu[i],0);
		math = getSubjectScore(&stu[i],1);
		eng = getSubjectScore(&stu[i],2);
		sum = jap + math + eng;
		japS += jap;
		mathS += math;
		engS += eng;
		sumS += sum;
		rank = getRank(&stu[i]);
		printf("|%4d | %-41s | %9d | %9d | %9d | %9d | %9d | %9.2lf |\n",i+1,getName(&stu[i],name),jap,math,eng,sum,rank,(double)sum/3);
    }
    printf("|-------------------------------------------------------------------------------------------------------------------------|\n");


    printf("\n\t\t\t\t\t合計 %14d %11d %11d %11d\n",japS,mathS,engS,sumS);
    printf("\t\t\t\t\t平均 %14.2lf %11.2lf %11.2lf %11.2lf\n\n",(double)japS/n,(double)mathS/n,(double)engS/n,(double)sumS/n);
    return;
}

/**
 * @brief Set the Ranking object
 *
 * @param n
 * @param stu
 */
void setRanking(int n,Exam stu[]){
	int rank;
	int sumN,sumC;
	for(int i=0;i<n;i++){
		rank = n + 1;
		for(int j=0;j<n;j++){
			sumN = getScoreSum(&stu[i]);
			sumC = getScoreSum(&stu[j]);
			if(sumN >= sumC){
				rank--;
			}
		}
		setRank(&stu[i],rank);
	}
	return;
}
/**
 * @brief output "*"
 *
 * @param n
 */
void outLine(int n){
	for(int i=0;i<n;i++){
		printf("*");
	}
	return;
}