#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

void doClassification(const char *arg0)
{
	char *arg1[1024];
	sprintf(arg1, "/home/john/caffe/build/examples/cpp_classification/classification.bin \
  /home/john/caffe/models/bvlc_reference_caffenet/deploy.prototxt \
  /home/john/caffe/models/bvlc_reference_caffenet/bvlc_reference_caffenet.caffemodel \
  /home/john/caffe/data/ilsvrc12/imagenet_mean.binaryproto \
  /home/john/caffe/data/ilsvrc12/synset_words.txt %s > infile", arg0);
	system(arg1);
}

void readPath(char **line)
{
	FILE *fp;
	int index1 = 0;
	int index2 = 0;
	char ch;
	int i = 0;
	char tmp[10][1024];

	*line = malloc(10 * 1024);
	fp = fopen("infile", "r");
	if(fp == NULL)
		ERR_EXIT("open file error");
/*
	for(i = 0; i < 10; i++)
	{
		memset(line[index1], 0, 1024);
		index1++;
	}
*/
	index1 = 0;
	while((ch = getc(fp)) != EOF)
	{
		if(ch != '\n')
		{
			tmp[index1][index2] = ch;
			index2++;
		}
		else
		{
			printf("%d %s\n", index1, tmp[index1]);
			index1++;
			index2 = 0;
		}
	}	
	
	int length = index1;
	printf("%d\n", length);

	char tmp1[10][1024];
	sprintf(tmp1[0], "<p align=\"center\">%s<br/>", tmp[0]);
	sprintf(tmp1[1], "%s<br/>", tmp[1]);
	sprintf(tmp1[2], "%s<br/>", tmp[2]);
	sprintf(tmp1[3], "%s<br/>", tmp[3]);
	sprintf(tmp1[4], "%s<br/></p>", tmp[4]);
	strcpy(*line, tmp1[0]);
	strcat(*line, tmp1[1]);
	strcat(*line, tmp1[2]);
	strcat(*line, tmp1[3]);
	strcat(*line, tmp1[4]);

	fclose(fp);
}
