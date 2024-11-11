ab=int(input().replace(' ',''))
print(['No','Yes'][any(i**2==ab for i in range(ab))])