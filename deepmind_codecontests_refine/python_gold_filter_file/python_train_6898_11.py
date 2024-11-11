from itertools import groupby 

t = int(input())
n = []
#for each test cases
for i in range(t):
    z = int(input())
    n.append(z)

def calc(x):
 arr = [int(d) for d in str(x)]
 score = 0
 res = [list(y) for x, y in groupby(arr)]
 alice = 1
 while(len(res)>=1):
     large = {
             "value": 0,
             "index": 0
         }
     for idx,x in enumerate(res): 
         if x[0] == 1:
             if(large['value']<len(x)):
                 large['value'] = len(x)
                 large["index"] = idx
     res.pop(large["index"])
     res = [j for i in res for j in i]

     res = [list(y) for x, y in groupby(res)]
     
     if(alice==1):
        alice = 0
        score += large["value"]
        
     else:
         alice = 1
     
     
     
 print(score)
 
for x in n:
    calc(x)
    