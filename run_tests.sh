#!/bin/bash

testps () {
    COUNT=$3
    LIMIT=$4
    ARG=`seq $COUNT | shuf | paste -sd " "`
    total=`$1 $ARG | wc -l`
    check=`$1 $ARG | $2 $ARG`
    out=""
    if [ $check != "OK" ];
    then
        out="Checker: KO\n $ARG"
    else
        out="Checker: OK"
    fi

    # if [ $max -eq 0 ];
    # then
    #   min=$total
    # fi
    # if [ $min -gt $total ];
    # then
    #   min=$total
    # fi
    # if [ $max -lt $total ];
    # then
    #   max=$total
    # fi

	if [ $total -gt $LIMIT ];
    then
        echo -e "$out\nOver $LIMIT - Total: $total - exceeded by: $(( $total - $LIMIT )) - Args: $ARG"
    else
        echo -e "$out\nOK"
    fi
}

for i in {1..50000};
do
    testps $1 $2 $3 $4
done

wait

# echo "Max: $max - Min: $min - Diff: $(( $max - $min ))"

# $1 push_swap exec
# $2 checker exec
# $3 N elements
# $4 max accepted moves

# total = num moves
