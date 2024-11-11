d1, d2, d3 = map(int, input().split())
List=[]
List.append(d1+d2+d3)
List.append(2*d1+2*d2)
List.append(2*d1+2*d3)
List.append(2*d2+2*d2)
print(min(List))