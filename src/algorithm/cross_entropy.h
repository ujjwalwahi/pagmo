/*****************************************************************************
 *   Copyright (C) 2004-2009 The PaGMO development team,                     *
 *   Advanced Concepts Team (ACT), European Space Agency (ESA)               *
 *   http://apps.sourceforge.net/mediawiki/pagmo                             *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Developers  *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Credits     *
 *   act@esa.int                                                             *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************/

#ifndef PAGMO_ALGORITHM_CROSS_ENTROPY_H
#define PAGMO_ALGORITHM_CROSS_ENTROPY_H

#include <string>


#include "../config.h"
#include "base.h"
#include "../population.h"
#include "../types.h"
#include "../serialization.h"
#include "../Eigen/Dense"




namespace pagmo { namespace algorithm {

/// Covariance Matrix Adaptation Evolutionary Startegy (CMAES)
/**

 */

class __PAGMO_VISIBLE cross_entropy: public base
{
public:
	cross_entropy(int gen = 500, double cc = -1, double cs = -1, double c1 = -1, double cmu = -1, double sigma0=0.5, double ftol = 1e-6, double xtol = 1e-6);
	base_ptr clone() const;
	void evolve(population &) const;
	std::string get_name() const;

	// Setters and Getters (needed for all as we want to fine control the iterations .... )
//	void set_gen(const int gen);
//	int  get_gen() const;

//	void   set_cc(const double p);
//	double get_cc() const;

//	void   set_cs(const double p);
//	double get_cs() const;

//	void   set_c1(const double p);
//	double get_c1() const;

//	void   set_cmu(const double p);
//	double get_cmu() const;

//	void   set_sigma(const double p);
//	double get_sigma() const;

//	void   set_xtol(const double p);
//	double get_xtol() const;

//	void   set_ftol(const double p);
//	double get_ftol() const;

	void set_screen_output(const bool p);
	bool get_screen_output() const;
protected:
	std::string human_readable_extra() const;
private:
	friend class boost::serialization::access;
		template <class Archive>
	void serialize(Archive &ar, const unsigned int)
	{
		ar & boost::serialization::base_object<base>(*this);
		ar & const_cast<std::size_t &>(m_gen);
		ar & m_cc;
		ar & m_cs;
		ar & m_c1;
		ar & m_cmu;
		ar & m_sigma;
		ar & m_xtol;
		ar & m_ftol;
		ar & m_screen_output;
		ar & mean;
		ar & variation;
		ar & newpop;
		ar & B;
		ar & D;
		ar & C;
		ar & invsqrtC;
		ar & pc;
		ar & ps;
		ar & counteval;
		ar & eigeneval;
	}
	// "Real" data members
	const std::size_t m_gen;
	double m_cc;
	double m_cs;
	double m_c1;
	double m_cmu;
	double m_sigma;
	double m_xtol;
	double m_ftol;
	bool m_screen_output;

	// "Memory" data members (these are here as to enable control over each single generation)
	mutable Eigen::VectorXd mean;
	mutable Eigen::VectorXd variation;
	mutable std::vector<Eigen::VectorXd> newpop;
	mutable Eigen::MatrixXd B;
	mutable Eigen::MatrixXd D;
	mutable Eigen::MatrixXd C;
	mutable Eigen::MatrixXd invsqrtC;
	mutable Eigen::VectorXd pc;
	mutable Eigen::VectorXd ps;
	mutable int counteval;
	mutable int eigeneval;
};

}} //namespaces

BOOST_CLASS_EXPORT_KEY(pagmo::algorithm::cross_entropy);

#endif // CROSS_ENTROPY_H
