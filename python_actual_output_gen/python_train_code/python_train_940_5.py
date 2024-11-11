S = "".join([i if i in 'ACGT' else ' ' for i in input()])
print(max([len(i) for i in S.split()]))