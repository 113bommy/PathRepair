songs_number, flash_drive_capacity = map(int, input().split())
deductions = []
total_size = 0
for i in range(songs_number):
    size, compressed_size = map(int, input().split())
    total_size += size
    deductions.append(size-compressed_size)
deductions.sort(reverse=True)
compressions_count = 0
i = 0
while i < songs_number and total_size > flash_drive_capacity:
    compressions_count += 1
    total_size -= deductions[i]
    i += 1
result = compressions_count if total_size < flash_drive_capacity else -1
print(result)
