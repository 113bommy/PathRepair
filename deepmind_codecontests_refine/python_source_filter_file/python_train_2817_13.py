s=input();u=s.upper();l=s.lower()
print(''.join([(l[i],u[i])[s[i]==u[i]]for i in range(len(s))]))