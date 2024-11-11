n, m = map(int, input().split())
sequence = list(map(int, input().split()))
fingerprints = list(map(int, input().split()))
result = []

for num in sequence:
    if num in fingerprints:
        result.append(str(num))
        
' '.join(result)