import string
import random
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
            n = int(input())
            ll = [int(i) for i in input().split(' ')]
            ll.sort()
            ls = []
            count=1
            if len(ll) ==1:
                    print(0)
                    continue
            for j in range(len(ll) -1):
                    if ll[j] == ll[j+1]:
                            count += 1
                    else:
                            ls.append(count)
                            count = 1
            ls.append(count)
            ls.sort()
            nbe = len(ls)
            nm = ls[nbe-1]
            res = min(nbe, nm)
            res = min(res, n//2)
            if nm == nbe and n//nbe == nm:
            	res = res - 1
            print(res)