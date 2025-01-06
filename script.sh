max=0
test=0

for i in {1..1000}
do
args=$(seq 100 200 | sort -R | tr "\n" " ")
res=$(./push_swap $args | wc -l)
if [ $res -gt $max ]; then
    test=$args
    max=$res
fi
done

echo $test
echo $max
