# remove binaries
rm producer consumer

# remove shared memory space
FILE=/dev/shm/producer-consumer
if [ -f "$FILE" ]; then
    rm $FILE
fi
