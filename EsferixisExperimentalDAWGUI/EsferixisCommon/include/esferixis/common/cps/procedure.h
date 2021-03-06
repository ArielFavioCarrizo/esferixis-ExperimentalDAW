/*
BSD 3-Clause License

Copyright (c) 2019, Ariel Favio Carrizo
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#ifdef __cplusplus
#include <cstddef>
#elif
#include "stddef.h"
#endif

#include <esferixis/common/cps/cont.h>
#include <esferixis/common/cps/exception.h>

EsferixisCommon_C_BEGIN

typedef struct _esferixis_cps_procedureContext {
	void *param;
	esferixis_cps_unsafecont cont;
} esferixis_cps_procedureContext;

EsferixisCommon_C_END

#ifdef __cplusplus
namespace esferixis {
	namespace cps {
		template<typename T>
		class ProcedureContext final {
		public:
			/**
			 * @post Creates a procedure context with
					 the specified parameter pointer and
					 the specified return continuation
			 */
			ProcedureContext(T *param, esferixis_cps_unsafecont cont) {
				this->c_context_m.param = (void *)param;
				this->c_context_m.cont = cont;
			}

			/**
			 * @post Sets the parameter value
			 */
			void setParameter(T *param) {
				this->c_context_m.param = (void *)param;
			}

			/**
			 * @post Sets the continuation
			 */
			void setCont(esferixis_cps_unsafecont cont) {
				this->c_context_m.cont = cont;
			}

			/**
			 * @post Gets the pointer to C context
			 */
			esferixis_cps_procedureContext * cContext() {
				return &(this->c_context_m);
			}

		private:
			esferixis_cps_procedureContext c_context_m;
		};
	}
}
#endif