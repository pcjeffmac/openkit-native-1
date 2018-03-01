/**
* Copyright 2018 Dynatrace LLC
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef _CORE_UTIL_COMMANDLINEARGUMENTS_H
#define _CORE_UTIL_COMMANDLINEARGUMENTS_H

#include "core/UTF8String.h"

namespace core 
{
	namespace util 
	{
		///
		/// Container for command line arguments
		///
		class CommandLineArguments
		{
		public:

			///
			/// Default constructor
			///
			CommandLineArguments();

			///
			/// Parse the command line and try to fill all required fields
			/// @param[in] argc number of arguments
			/// @param[in] argv array of strings with the arguments
			///
			void parse(uint32_t argc, char* *argv);

			///
			/// Get the application id
			/// @returns the parsed application id or an empty string
			///
			const core::UTF8String getApplicationID() const;

			///
			/// Get the beacon URL
			/// @returns the parsed beacon URL or an empty string
			///
			const core::UTF8String getBeaconURL() const;

			///
			/// Get the server id
			/// @returns the parsed server id or @c -1 in case of failure to parse the server ID
			///
			int32_t getServerID() const;

			///
			/// Returns a flag if a connect attempt can be made given the available arguments
			/// @returns @c true if all parameters for a server connection are available,  @c false if arguments are missing
			///
			bool isValidConfiguration() const;

			///
			/// Print a help message about command line usage and the missing arguments
			///
			static void printHelp();
		private:

			/// Server ID
			int32_t mServerID;

			/// application version
			core::UTF8String mApplicationID;

			/// beacon URL
			core::UTF8String mBeaconURL;
		};
	}
}

#endif