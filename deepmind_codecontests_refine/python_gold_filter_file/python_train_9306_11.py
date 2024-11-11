import sys

def f(n, d, array):
    sa = sorted(array)
    diff = [0] * n
    answer = 0
    for i, a in enumerate(array):
        if i>0:
            diff[i] = sa[i] - sa[i-1]
    for i, a in enumerate(array): 
        j = i + 1
        if j < n: 
            dist = diff[j]
            while dist <= d:
                answer += 1
                j += 1
                if j == n:
                    break
                dist += diff[j]
    return answer*2

if __name__ == '__main__':
    for line in sys.stdin:
        n_d = [int(v) for v in line.split()]
        n, d = n_d[0], n_d[1]
        array = [int(a) for a in sys.stdin.readline().split()]
        answer = f(n, d, array)
        print(answer)
