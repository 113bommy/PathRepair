import sys
input = sys.stdin.readline
print = sys.stdout.write;thing = [2,3,5,7,9,11,13,17,23,29]
for i in range(int(input())):
    a = int(input())
    a-=1
    for i in thing:
        if a%i != 0:
            print(" ".join([str(i),str(a-i),str(1)])+'\n')
            break
            
