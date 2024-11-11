S,T = input(),input()

print(sum(int(a==b) for a,b zip(S,T)))