#!/usr/local/bin/python3.4
import pdb
import sys

def isQpassSergei(studens_in_column, SergeiX, SergeiY, left_questions):
   
    return True  if  (SergeiX -1) * studens_in_column + SergeiY - 1 <  left_questions else False 
        
def isYpassSergei(column, studens_in_column, SergeiX, SergeiY, left_questions):

    left_questions-= column * studens_in_column
    
    if left_questions == 0:
        return False
    if SergeiX == column: 
        return False
    return True if  (column - SergeiX - 1) * studens_in_column + \
            SergeiY  <=  left_questions else False 

rows, studens_in_column, questions,SergeiX, SergeiY = map( int, input().split())

min_question=0
max_question=0
sergei_question=0

if rows == 1:
    min_question = questions //  studens_in_column
    max_question = min_question + 1 if questions % studens_in_column != 0 else  min_question
    sergei_question = min_question if  questions % studens_in_column < SergeiY else  max_question
    print (max_question, min_question, sergei_question)
    sys.exit(0)

min_question  = questions  // ((2*rows-2)*studens_in_column)
max_question  = 2 * min_question
left_questions = questions %  ((2*rows-2) * studens_in_column)
sergei_question = min_question if  SergeiX  == rows or SergeiX == 1 else max_question
xx=0 
if left_questions == 0 and rows != 2:
    
    xx

elif rows  == 2 :
    max_question = min_question
    if left_questions == 0:
        xx
    elif left_questions < rows  * studens_in_column:
        if left_questions < studens_in_column:
            max_question = max_question + 1
            sergei_question = min_question + 1 if isQpassSergei(studens_in_column, SergeiX, SergeiY, left_questions) else min_question    
        else:
            max_question = min_question + 1
            sergei_question = min_question + 1 if isQpassSergei(studens_in_column, SergeiX, SergeiY, left_questions) else min_question
    else:
        sergei_question =  min_question = max_question = min_question+1

elif  left_questions < rows*studens_in_column:
    if max_question == 0 and left_questions != 0:
        max_question+=1
    elif left_questions  >  studens_in_column:
        max_question+=1

    sergei_question= sergei_question+1 if isQpassSergei(studens_in_column, SergeiX, SergeiY, left_questions) else sergei_question 
        
else:
    max_question = max_question + 1 if left_questions == rows * studens_in_column  else max_question + 2
    min_question+=1
    sergei_question = sergei_question+2 if isYpassSergei(rows, studens_in_column, SergeiX, SergeiY, left_questions) else sergei_question + 1

print (max_question, min_question, sergei_question)
        
