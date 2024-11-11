t = int(input())
while(t > 0):
    l = [int(i) for i in input().split()]
    n = l[0]
    m = l[1]
    marks = [int(i) for i in input().split()]
    s = sum(marks[1:])
    if(s + marks[0] > m):
        print(m)
        t -= 1
        continue
    print(s + marks[0])
    t -= 1
