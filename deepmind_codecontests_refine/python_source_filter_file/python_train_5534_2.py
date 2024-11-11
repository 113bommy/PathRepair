def get_tail(k):
    return (k*(k-1))//2

def find_starter(n, k):
    f = get_tail(k)
    starter = (n-f)//k
    return starter

def answerYES(A):
    return "YES\n"+" ".join(map(str, A))

def get_array(n, k):
    starter = find_starter(n, k)
    if starter == 0:
        return "NO"
    A = [0]*k
    s = 0
    last = starter+k-1
    for i in range(starter, starter+k):
        A[i-starter] = i
        s+=i
    diff = n-s
    maxe = last-2
    if diff > maxe:
        while diff > 0 and A[-2]*2 - A[-1] >= 1:
            for i in range(k-1, -1, -1):
                if i-1 > -1 and A[i-1]*2 - A[i] >= 1:
                    A[i] += 1
                    diff -= 1
                    if diff == 0:
                        break
        if diff == 0:
            return answerYES(A)
        else:
            return "NO"
        
    else:
        A[-1] += diff
        return answerYES(A)
    return "NO"

n, k = map(int, input().split())
print(get_array(n, k))
