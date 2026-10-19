//
// Created by markt on 2026. 10. 05..
//

#include " Polynomial.h"
#include <cmath>
Polynomial::Polynomial(int degree, const double coefficients[]) {
        this->capacity = degree + 1;
        this->coefficients = new double[this->capacity];
        for (int i = 0; i < this->capacity; ++i) {
                this->coefficients[i] = coefficients[i];
        }
}
//copy konstruktor
Polynomial::Polynomial(const Polynomial &that) {
        this->capacity = that.capacity; //atmasolasok
        this->coefficients = new double[this->capacity];
       for (int i = 0; i < this->capacity; ++i) {
               this->coefficients[i] = that.coefficients[i];
       }
}

int Polynomial::degree() const {
        return this->capacity-1; //lekerdezzuk a fokat vagyis a legnagyobb hatvanyt
}

Polynomial operator +(const Polynomial &a, const Polynomial &b) {
        int degA = a.degree();
        int degB = b.degree();

         //az uj fokszám a ket fokszám maximuma lesz
        int maxDeg = (degA > degB) ? degA : degB;


        double *newCoeffs = new double[maxDeg + 1];


        for (int i = 0; i <= maxDeg; ++i) {
                double coeffA = 0, coeffB = 0;
                int power = maxDeg - i;


                if (power <= degA) {
                        coeffA = a.coefficients[degA - power];
                }

                if (power <= degB) {
                        coeffB = b.coefficients[degB - power];
                }


                newCoeffs[i] = coeffA + coeffB;
        }


        Polynomial result(maxDeg, newCoeffs);


        delete[] newCoeffs;

        return result;
}

double Polynomial :: evaluate(double x ) const {
        double result = this->coefficients[0];
        for (int i = 1; i < this->capacity; ++i) {
                result = result * x  + this->coefficients[i] ;
        }
        return result;
}

ostream & operator <<(ostream& out, const Polynomial &what) {
        int deg = what.degree();
        bool first = true;

        for (int i = 0; i <= deg; ++i) {
                double coeff = what.coefficients[i];
                if (coeff == 0) continue;

                int power = deg - i;
                if (!first) {
                        if (coeff > 0) out << " + ";
                        else { out << " - "; coeff = -coeff; }
                } else {
                        if (coeff < 0) { out << "-"; coeff = -coeff; }
                }

                if (coeff != 1 || power == 0) {
                        out << coeff;
                }
                if (power > 0) {
                        out << "x";
                        if (power > 1) out << "^" << power;
                }
                first = false;
        }
        if (first) out << "0";
        return out;
}
Polynomial operator -(const Polynomial &a) {
        double *newCoeffs = new double[a.capacity];
        for (int i = 0; i < a.capacity; ++i) {
                newCoeffs[i] = -a.coefficients[i];
        }
        Polynomial result(a.degree(), newCoeffs);
        delete[] newCoeffs;
        return result;
}

Polynomial operator *(const Polynomial &a, const Polynomial &b) {
        int degA = a.degree();
        int degB = b.degree();
        int newDeg = degA + degB;
        double *newCoeffs = new double[newDeg + 1]();

        for (int i = 0; i <= degA; ++i) {
                for (int j = 0; j <= degB; ++j) {
                        newCoeffs[i + j] += a.coefficients[i] * b.coefficients[j];
                }
        }

        Polynomial result(newDeg, newCoeffs);
        delete[] newCoeffs;
        return result;
}

Polynomial Polynomial::derivative() const {
        int n= this->degree();
        if ( n==0 ) {
                double zero[]= {0.0};
                return Polynomial(0, zero);
        }

        double *derivalt= new double[n];
        for (int i = 0; i < n; ++i) {
                int hatvany= n - i;
                derivalt[i]= hatvany * this->coefficients[i];


        }
        Polynomial result(n-1, derivalt);
        delete[] derivalt;
        return result;

}


Polynomial::~Polynomial() {
        delete[] this->coefficients;
}

