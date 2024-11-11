d = {'a': 0, 'b': 1}
def process(s, t, k):
    n = len(s)
    answer = 0
    D = 0
    final_i = n
    for i in range(n):
        d1 = d[s[i]]
        d2 = d[t[i]]
        D = 2*(D)+d2-d1
        if D < k:
            answer+=D
        else:
            final_i = i
            break 
    answer+=k*(n-final_i)
    return answer

n, k = [int(x) for x in input().split()]
s = input()
t = input()
print(process(s, t, k))