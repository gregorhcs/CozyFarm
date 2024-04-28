pipeline {
    agent none
	
	options {
		disableConcurrentBuilds()
		disableResume()
	}
    
	stages {
        stage('initialize') {
			parallel {
				stage('boot-windows') {
					agent {
						label 'windows && unreal'
					}
					stages {
						stage('checkout-windows') {
							steps {
								checkout scm
							}
						}
						stage('gen-project-files-windows') {
							steps {
								bat "\"C:/Program Files/Epic Games/UE_5.4/Engine/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool.exe\" -projectfiles -project=\"$WORKSPACE\\CozyScape.uproject\""
							}
						}
						stage('build-windows') {
							steps {
								bat "\"C:/Program Files/Epic Games/UE_5.4/Engine/Build/BatchFiles/RunUAT\" BuildCookRun -project=\"$WORKSPACE\\CozyScape.uproject\" -clientconfig=Development -targetplatform=Win64 -noP4 -cook -allmaps -build -stage -pak -archive -archivedirectory=\"$WORKSPACE\\builds\""
							}
						}
						stage('compile-blueprints-windows') {
							steps {
								bat "\"C:/Program Files/Epic Games/UE_5.4/Engine/Binaries/Win64/UnrealEditor-Cmd.exe\" \"$WORKSPACE\\CozyScape.uproject\" -run=CompileAllBlueprints"
							}
						}
						stage('archive-windows') {
							steps {
								zip(zipFile: 'build-windows.zip', dir: 'builds/Windows', archive: true, overwrite: true)
							}
						}
					}
				}
				/* stage('boot-linux') {
					agent {
						docker {
							image 'ghcr.io/epicgames/unreal-engine:dev-slim-5.3'
							label 'linux && docker'
							registryUrl 'https://ghcr.io'
							registryCredentialsId 'Faulo-GitHub'
						}
					}
					stages {
						stage('checkout-linux') {
							steps {
								checkout scm
							}
						}
						stage('build-linux') {
							steps {
								sh 'chmod -R 777 /root'
								sh 'chmod -R 777 .'
								sh "sudo -u ue4 /home/ue4/UnrealEngine/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -project='$WORKSPACE/RacoonGame/RacoonGame.uproject' -clientconfig=Development -targetplatform=Linux -noP4 -cook -allmaps -build -stage -pak -archive -archivedirectory='$WORKSPACE/builds'"
							}
						}
						stage('archive-linux') {
							steps {
								zip(zipFile: 'build-linux.zip', dir: 'builds/Linux', archive: true, overwrite: true)
							}
						}
					}
				} */
			}
		}
	}
	post {
	    always {
            discordSend description: "Jenkins Pipeline Build", footer: "Fresh out of the oven!", link: env.BUILD_URL, result: currentBuild.currentResult, title: JOB_NAME, webhookURL: "https://discord.com/api/webhooks/1212063051348443226/brnE5bRKcwJinkEd7XBad38uzJ50PyysD1-YPe6uNSi-MMoWHBhS3rCp8YYz092VwHFS"
	    }
	}
}
