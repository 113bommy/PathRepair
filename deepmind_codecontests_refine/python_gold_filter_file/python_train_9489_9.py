n = int(input())
inputlist = input().split(" ")
arr = []
for i in inputlist:
    arr += [int(i)]

def is_sorted(listed):
    return listed == sorted(listed)


def maxim(a,b):
    if a>b:
        return a
    else:
        return b



def thanos_snap(listed):
    if is_sorted(listed):
        return len(listed)
    else:
        return maxim(thanos_snap(listed[0:len(listed)//2]), thanos_snap(listed[(len(listed)//2): len(listed)]))


print(thanos_snap(arr))

