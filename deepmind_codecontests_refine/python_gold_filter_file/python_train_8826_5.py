#!/usr/bin/env python3
import sys
import collections

def solve(N: int, A: "List[int]"):
    counter = sorted(list(collections.Counter(A).values()),reverse=True)
    c_index = 0
    k=0
    for i in range(1,N+1):
        k+=1
        if len(counter)<i:
            print(0)
            continue
        while counter[c_index]*k > N and c_index<len(counter)-1:
            N-=counter[c_index]
            c_index+=1
            k-=1
        print(N//k)
    return

def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    A = [int(next(tokens)) for _ in range(N)]  # type: "List[int]"
    solve(N, A)

if __name__ == '__main__':
    main()
