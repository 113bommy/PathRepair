import math
total = []
arr = []
def setDatas(count):
   array = []
   for i in range(count):
      countPlates = int(input())
      arr = input().split(' ')
      array.append(arr)
   return array   

def refactoring(arr, minimum):
      count = 0
      for i in range(len(arr)):
         if arr[i] >= minimum:
            count += 1
      if count < minimum:
         return True 
      return False   

def complete():
   countDatas = int(input())
   countDatas = setDatas(countDatas)
   for i in range(len(countDatas)):
      countDatas[i] = list(map(int, countDatas[i]))
      minimum = 0
      for j in range(len(countDatas[i])):
             minimum += countDatas[i][j]
      minimum = math.floor((minimum / len(countDatas[i])) / 2)
      while True:
         minimum += 1    
         res = refactoring(countDatas[i], minimum)
         if res == True:
            break
      total.append(minimum - 1)   
   for i in range(len(total)):
      print(int(total[i]))   

complete()