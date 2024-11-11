n = int(input())
queue = list(map(int, input().split()))

queue.sort()
res = 1
total = 0
i = 0
while i < len(queue):
    if total <= queue[i]:
        res += 1
        total += queue[i]
    i += 1
               
print(res)

"""
# Test 3
10
13 2 5 55 21 34 1 8 1 3

1 1 2 3 5 8 13 21 34 55
   3 5 8 13 21 34 55
Ans: 6

def answer(n, t):
    t.sort()
    wait_time = 0
    happy_people = 0
    for i in range(n):
        if t[i] >= wait_time:
            happy_people += 1
            wait_time += t[i]
    return happy_people
 
def main():
    n = int(input())
    t = [int(i) for i in input().split()]
    print(answer(n, t))
    
# answer 2
n = int(input())
*t, = map(int, input().split())
t.sort()
a = 0
c = 0
for i in t:
    if c <= i:
        c += i
        a += 1
print(a)
"""