""" Problem link - https://codeforces.com/problemset/problem/1613/C """

def attack_value(fs,k):
    attack = 0
    for i in range(len(fs)-1):
        if k + fs[i] <= fs[i+1]:
            attack = attack + k
        else:
            attack = attack + (fs[i+1] - fs[i])
    return attack + k
def k_value(n,h,fs):
    final_mid = h + 1
    start = 1
    end = h
    while(start<end):
        mid = ( start + end )//2
        attack = attack_value(fs,mid)
        if attack < h:
            #final_attack = min(final_attack,attack)
            start = mid + 1 
        else:
            final_mid = min(final_mid,mid)
            end = mid - 1
    return final_mid

            


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n,h = input().split()
        n,h = int(n),int(h)
        fs = [int(x) for x in input().split()]
        final_mid = k_value(n,h,fs)
        print(final_mid)