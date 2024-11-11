t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    while(s.count('()')!=0):
        s = s.replace('()','')
    
    print(len(s)/2)