import heapq

def get_ans(letter, words):
    heap=[]
    for w in words:
        gc=w.count(letter)
        heapq.heappush(heap, len(w)-2*gc)

    cnt=0
    for i in range(len(heap)):
        cnt -= heapq.heappop(heap)
        if cnt<=0:
            return i

    return len(words)


def solve():
    # put code here
    n=int(input())
    words = [input() for _ in range(n)]
    ans=0
    for l in 'abcde':
        ans = max(ans, get_ans(l, words))
        #print(l, get_ans(l, words))
    print(ans)


t = int(input())
for _ in range(t):
    solve()