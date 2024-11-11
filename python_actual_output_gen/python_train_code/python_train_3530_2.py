nb_steward = int(input())
strengths  = [int(x) for x in input().split()]
mins  = strengths.count(min(strengths))
maxs  = strengths.count(max(strengths))
print(nb_steward - mins - maxs)
