#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH	1001
#define MAX_WORD_LENGTH		21

void SetOneSentence(char * sentenceBuffer);
void ReverseWordsInSentence(char * sentenceBuffer, char * reverseBuffer);

int main()
{
	int testCaseNumber;
	char inputBuffer[MAX_STRING_LENGTH];
	char outputBuffer[MAX_STRING_LENGTH];

	scanf("%d", &testCaseNumber);
	scanf("%c", inputBuffer);		// input buffer에 들어있는 개행문자를 뻬냄

	while (testCaseNumber--)
	{
		memset(inputBuffer, 0, sizeof(inputBuffer));
		memset(outputBuffer, 0, sizeof(outputBuffer));
		
		SetOneSentence(inputBuffer);
		ReverseWordsInSentence(inputBuffer, outputBuffer);
		printf("%s\n", outputBuffer);
	}

	return 0;
}

void SetOneSentence(char * sentenceBuffer)
{
	int inputIndex;
	char c;

	inputIndex = 0;

	while (1)
	{
		scanf("%c", &c);
		
		if (c == '\n')
		{
			break;
		}
		else
		{
			sentenceBuffer[inputIndex++] = c;
		}
	}
}

void ReverseWordsInSentence(char * sentenceBuffer, char * reverseBuffer)
{
	int readIndex;
	int writeIndex;
	int wordStartIndex;
	int wordEndIndex;

	int i;

	readIndex = 0;
	writeIndex = 0;

	while (readIndex < MAX_STRING_LENGTH && sentenceBuffer[readIndex] != '\0')
	{
		// calc word index info
		wordStartIndex = readIndex;
		while (sentenceBuffer[readIndex] != ' ' && sentenceBuffer[readIndex] != '\0')
		{
			readIndex++;
		}
		wordEndIndex = readIndex - 1;

		// set reverse word to output buffer
		for (i = wordEndIndex; i >= wordStartIndex; i--)
		{
			reverseBuffer[writeIndex++] = sentenceBuffer[i];
		}

		// set white space or null character
		reverseBuffer[writeIndex++] = sentenceBuffer[readIndex];

		readIndex++;
	}
}
