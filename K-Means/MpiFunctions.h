#pragma once

#include "Const.h"
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define FINISH_WORK_TAG 999

static MPI_Datatype PointMPIType;

void mpiInit(int *argc, char** argv[], int *rank, int *numberOfProcesses);
void commitMpiPointType();
void scatterPoints(int rank, int numberOfProcesses, point_t* allPoints, int N, point_t** myPoints, int *numberOfPoints);
point_t* gatherPoints(int rank, int numberOfProcesses, point_t* myPoints, int numberOfPointsToSend);
bool* gatherBool(int rank, int numberOfProcesses, bool check);
void collectPointsInClusters(int rank, int numberOfProcesses, int numberOfClusters, point_t** points, int *pointsInClusters);
double* masterWorkCalcQ(int numberOfProcesses, point_t** pointsInClusters, int* numberOfPointInClusters, int numberOfClusters);
point_t* slavesWorkCalcQ(int *workSize, int *clusterId, double distance, bool found);