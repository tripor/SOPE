if [ -f run ]; then
  rm run
fi

if  gcc -Wall -o run $1.c 2> error.txt ; then
  #statements
  ./run
else
  echo "COMPILATION ERROR"
fi
