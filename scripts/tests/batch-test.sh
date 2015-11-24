#!/bin/bash
cd ../em-estimation/
N_ITERS=100
for i in $(seq 1 $N_ITERS)
do
  echo "Iteración $i"
  octave --silent batch-experiment.m
done
