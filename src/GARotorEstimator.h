#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <vector>

Eigen::Quaterniond GARotorEstimator(const std::vector<Eigen::Vector3d>& P, const std::vector<Eigen::Vector3d>& Q, const size_t N, const std::vector<double>& w);
Eigen::Quaterniond GARotorEstimator(const Eigen::Matrix3d& M, const double S);
