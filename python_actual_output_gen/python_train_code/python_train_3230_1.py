all = {}
result = {} 


def handle(string): 
    sset = set()
    for i in range(len(string)):
        for j in range(i+1,len(string)+1):
            sset.add(string[i:j])
    for s in sset:
        if s not in all:
            all[s] = 0
        all[s] += 1 
        result[s] = s
    
 

N = int(input())

for i in range(N):
    handle(input())
    
Q = int(input())
for i in range(Q):
    #Query.append(input())
    q = input()
    if q in all:
        print ("%d %s" %(all[q],result[q]))
    else:
        print ("0 -")
